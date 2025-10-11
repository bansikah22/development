#!/bin/bash

# QR Menu Generator - Deployment Script
# This script handles deployment to different environments with minimal configuration

set -e

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Default values
ENVIRONMENT="production"
SKIP_BUILD=false
SKIP_TESTS=false
CONFIG_FILE=""

# Function to print colored output
print_status() {
    echo -e "${BLUE}[INFO]${NC} $1"
}

print_success() {
    echo -e "${GREEN}[SUCCESS]${NC} $1"
}

print_warning() {
    echo -e "${YELLOW}[WARNING]${NC} $1"
}

print_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

# Function to show usage
show_usage() {
    cat << EOF
QR Menu Generator - Deployment Script

Usage: $0 [OPTIONS]

OPTIONS:
    -e, --environment ENV    Deployment environment (development|staging|production)
    -c, --config FILE       Custom configuration file (overrides .env)
    -s, --skip-build        Skip Docker build process
    -t, --skip-tests        Skip running tests
    -h, --help             Show this help message

EXAMPLES:
    # Deploy to production with default settings
    $0

    # Deploy to staging environment
    $0 --environment staging

    # Deploy with custom config file
    $0 --config /path/to/custom.env

    # Quick deployment (skip build and tests)
    $0 --skip-build --skip-tests

CONFIGURATION:
    The script looks for configuration in this order:
    1. Custom config file (if specified with -c)
    2. .env file in current directory
    3. .env.template as fallback

    For first-time deployment, copy .env.template to .env and modify as needed.

EOF
}

# Parse command line arguments
while [[ $# -gt 0 ]]; do
    case $1 in
        -e|--environment)
            ENVIRONMENT="$2"
            shift 2
            ;;
        -c|--config)
            CONFIG_FILE="$2"
            shift 2
            ;;
        -s|--skip-build)
            SKIP_BUILD=true
            shift
            ;;
        -t|--skip-tests)
            SKIP_TESTS=true
            shift
            ;;
        -h|--help)
            show_usage
            exit 0
            ;;
        *)
            print_error "Unknown option: $1"
            show_usage
            exit 1
            ;;
    esac
done

# Function to check prerequisites
check_prerequisites() {
    print_status "Checking prerequisites..."
    
    # Check if Docker is installed and running
    if ! command -v docker &> /dev/null; then
        print_error "Docker is not installed. Please install Docker first."
        exit 1
    fi
    
    if ! docker info &> /dev/null; then
        print_error "Docker daemon is not running. Please start Docker first."
        exit 1
    fi
    
    # Check if docker-compose is available
    if ! command -v docker-compose &> /dev/null && ! docker compose version &> /dev/null; then
        print_error "Docker Compose is not available. Please install Docker Compose."
        exit 1
    fi
    
    print_success "Prerequisites check passed"
}

# Function to load configuration
load_configuration() {
    print_status "Loading configuration..."
    
    # Determine config file to use
    if [[ -n "$CONFIG_FILE" ]]; then
        if [[ -f "$CONFIG_FILE" ]]; then
            source "$CONFIG_FILE"
            print_success "Loaded custom configuration from $CONFIG_FILE"
        else
            print_error "Custom config file not found: $CONFIG_FILE"
            exit 1
        fi
    elif [[ -f ".env" ]]; then
        source ".env"
        print_success "Loaded configuration from .env"
    elif [[ -f ".env.template" ]]; then
        print_warning "Using default configuration from .env.template"
        print_warning "Consider creating a .env file for your specific environment"
        source ".env.template"
    else
        print_warning "No configuration file found. Using default values."
    fi
    
    # Set environment-specific defaults
    export ENVIRONMENT="${ENVIRONMENT}"
    
    print_status "Environment: ${ENVIRONMENT}"
    print_status "Frontend Port: ${FRONTEND_PORT:-80}"
    print_status "Backend Port: ${BACKEND_PORT:-8080}"
}

# Function to run tests
run_tests() {
    if [[ "$SKIP_TESTS" == "true" ]]; then
        print_warning "Skipping tests (--skip-tests flag used)"
        return 0
    fi
    
    print_status "Running tests..."
    
    # Backend tests
    print_status "Running backend tests..."
    cd backend
    if ./mvnw test -q; then
        print_success "Backend tests passed"
    else
        print_error "Backend tests failed"
        exit 1
    fi
    cd ..
    
    # Frontend tests (if npm test script exists)
    if grep -q '"test"' frontend/package.json; then
        print_status "Running frontend tests..."
        cd frontend
        if npm test; then
            print_success "Frontend tests passed"
        else
            print_error "Frontend tests failed"
            exit 1
        fi
        cd ..
    else
        print_warning "No frontend tests configured"
    fi
}

# Function to build and deploy
build_and_deploy() {
    print_status "Starting deployment process..."
    
    # Create necessary directories
    mkdir -p logs data
    
    if [[ "$SKIP_BUILD" == "true" ]]; then
        print_warning "Skipping build process (--skip-build flag used)"
    else
        print_status "Building Docker images..."
        
        # Choose appropriate docker-compose command
        if command -v docker-compose &> /dev/null; then
            COMPOSE_CMD="docker-compose"
        else
            COMPOSE_CMD="docker compose"
        fi
        
        # Build images
        if $COMPOSE_CMD build --parallel; then
            print_success "Docker images built successfully"
        else
            print_error "Failed to build Docker images"
            exit 1
        fi
    fi
    
    print_status "Starting services..."
    
    # Stop existing containers
    $COMPOSE_CMD down 2>/dev/null || true
    
    # Start services
    if $COMPOSE_CMD up -d; then
        print_success "Services started successfully"
    else
        print_error "Failed to start services"
        exit 1
    fi
    
    # Wait for services to be ready
    print_status "Waiting for services to be ready..."
    sleep 10
    
    # Check if services are running
    if $COMPOSE_CMD ps | grep -q "Up"; then
        print_success "All services are running"
        
        # Show service status
        print_status "Service status:"
        $COMPOSE_CMD ps
        
        # Show access URLs
        echo ""
        print_success " Deployment completed successfully!"
        echo ""
        print_status "Access your application at:"
        echo "  Frontend: http://localhost:${FRONTEND_PORT:-80}"
        echo "  Backend API: http://localhost:${BACKEND_PORT:-8080}/api"
        echo "  Health Check: http://localhost:${BACKEND_PORT:-8080}/actuator/health"
        if [[ "$ENVIRONMENT" != "production" ]]; then
            echo "  H2 Console: http://localhost:${BACKEND_PORT:-8080}/h2-console"
        fi
        echo ""
        print_status "Useful commands:"
        echo "  View logs: $COMPOSE_CMD logs -f"
        echo "  Stop services: $COMPOSE_CMD down"
        echo "  Restart services: $COMPOSE_CMD restart"
        
    else
        print_error "Some services failed to start properly"
        print_status "Checking service logs..."
        $COMPOSE_CMD logs
        exit 1
    fi
}

# Main execution
main() {
    print_status "QR Menu Generator Deployment Script"
    print_status "Environment: $ENVIRONMENT"
    echo ""
    
    check_prerequisites
    load_configuration
    run_tests
    build_and_deploy
}

# Execute main function
main