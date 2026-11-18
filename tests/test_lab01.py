import pathlib
import subprocess
import unittest

ROOT = pathlib.Path(__file__).resolve().parents[1]

class Lab01Tests(unittest.TestCase):
    def test_register_demo(self):
        result = subprocess.run([str(ROOT / "build/registers")], capture_output=True, text=True, check=True)
        self.assertIn("sum=18", result.stdout)

    def test_safe_copy_rejects_oversize(self):
        result = subprocess.run([str(ROOT / "build/safe_copy")], capture_output=True, text=True, check=True)
        self.assertIn("accepted=SEP", result.stdout)
        self.assertIn("rejected=overlong input", result.stdout)

if __name__ == "__main__":
    unittest.main()
