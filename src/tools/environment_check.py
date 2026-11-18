#!/usr/bin/env python3
import platform
import shutil
import subprocess

print("machine:", platform.machine())
print("system:", platform.platform())
for command in ("clang", "lldb", "git", "python3"):
    print(f"{command}:", shutil.which(command) or "missing")
if platform.system() == "Darwin":
    subprocess.run(["sw_vers"], check=False)
