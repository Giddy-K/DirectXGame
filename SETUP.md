# DirectX Game Engine Setup Instructions

Follow these steps to set up and build the engine locally.

---

## Manual Setup (Recommended for first-time build)

1. Open the solution file (`.sln`) in **Visual Studio**.  
2. In the toolbar, change the build configuration to **x64**.  
3. Open **Project Properties**:
   - Under **General**, set:
     - **Output Directory** → `Bin\$(Platform)\$(Configuration)\`
     - **Intermediate Directory** → `Intermediate\$(Platform)\$(Configuration)\`
   - Under **C/C++ → Language**, set:
     - **C++ Language Standard** → `ISO C++20 Standard (/std:c++20)`
   - Under **C/C++ → General**, enable:
     - **Multi-processor Compilation** → `Yes (/MP)`

Then build and run the project.

---

## Automated Setup (Optional)

You can automate the setup by running this PowerShell script.

Save the following as **`setup.ps1`** in the project root:

```powershell
Write-Host "Setting up DirectX Engine environment..."

# Force x64 build
& msbuild .\YourGameEngine.sln /p:Platform=x64 /p:Configuration=Debug

# Configure output directories automatically
(Get-Content .\YourGameEngine.vcxproj) -replace 'OutDir>.*?</OutDir>', 'OutDir>Bin\$(Platform)\$(Configuration)\</OutDir>' | Set-Content .\YourGameEngine.vcxproj

Write-Host "Setup complete. Ready to build!"

Then run it from PowerShell:
```powershell
.\setup.ps1
```
