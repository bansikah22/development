import unittest
from app.monitor import get_metrics

class TestMonitor(unittest.TestCase):
    def test_get_metrics(self):
        metrics = get_metrics()
        self.assertIn("cpu_percent", metrics)
        self.assertIn("memory_percent", metrics)

if __name__ == "__main__":
    unittest.main()
