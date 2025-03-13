function updateChart() {
    fetch('/api/metrics')
        .then(response => response.json())
        .then(data => {
            const time = new Date().toLocaleTimeString();
            performanceChart.data.labels.push(time);
            
            performanceChart.data.datasets[0].data.push(data.cpu_percent);
            performanceChart.data.datasets[1].data.push(data.memory_percent);
            performanceChart.data.datasets[2].data.push(data.disk_percent);

            if (performanceChart.data.labels.length > 20) {
                performanceChart.data.labels.shift();
                performanceChart.data.datasets.forEach(dataset => dataset.data.shift());
            }
            performanceChart.update();
        });
}

const ctx = document.getElementById('performanceChart').getContext('2d');
const performanceChart = new Chart(ctx, {
    type: 'line',
    data: {
        labels: [],
        datasets: [
            {
                label: 'CPU Usage (%)',
                data: [],
                borderColor: '#2980b9',
                backgroundColor: 'rgba(41, 128, 185, 0.1)',
                fill: true
            },
            {
                label: 'Memory Usage (%)',
                data: [],
                borderColor: '#27ae60',
                backgroundColor: 'rgba(39, 174, 96, 0.1)',
                fill: true
            },
            {
                label: 'Disk Usage (%)',
                data: [],
                borderColor: '#e74c3c',
                backgroundColor: 'rgba(231, 76, 60, 0.1)',
                fill: true
            }
        ]
    },
    options: {
        responsive: true,
        scales: {
            y: {
                beginAtZero: true,
                max: 100,
                title: {
                    display: true,
                    text: 'Percentage (%)'
                }
            },
            x: {
                title: {
                    display: true,
                    text: 'Time'
                }
            }
        },
        plugins: {
            legend: {
                position: 'top'
            }
        }
    }
});

setInterval(updateChart, 5000); // Update every 5 seconds
