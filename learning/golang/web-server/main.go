package main

import (
	"log/slog"
	"net/http"
	"os"

	"web-server/handlers"
)

func main() {
	logger := slog.New(slog.NewTextHandler(os.Stdout, &slog.HandlerOptions{Level: slog.LevelInfo}))
	slog.SetDefault(logger)

	slog.Info("Starting HTTPS server", "port", ":8443") // Changed port to 8443 (common for HTTPS dev)

	fileServer := handlers.SetupStaticFileServer("./static")
	http.Handle("/", handlers.LoggingMiddleware(fileServer))
	http.Handle("/hello", handlers.LoggingMiddleware(http.HandlerFunc(handlers.HelloHandler)))
	http.Handle("/form", handlers.LoggingMiddleware(http.HandlerFunc(handlers.FormHandler)))

	// Use ListenAndServeTLS with cert and key files
	if err := http.ListenAndServeTLS(":8443", "cert.pem", "key.pem", nil); err != nil {
		slog.Error("Server failed", "error", err)
		os.Exit(1)
	}
}