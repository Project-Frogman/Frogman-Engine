/*
Copyright © from 2022 to present, UNKNOWN STRYKER (Hojin Lee / Joey). All Rights Reserved.

Licensed under the Frogman Engine License (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    https://github.com/UnknownStryker-Interactive-Technologies/Frogman-Engine-License/blob/release/LICENSE.md

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
using Launcher;
using System;
using System.Diagnostics;




public class EditortimeFroggy : Froggy
{
    public ProjectConfig ProjectConfig { get; set; } = new();
}

namespace Launcher.Script
{
    public class Main : Launcher.ScriptMain
    {
        public Main()
        {
        }

        public override void CreateGameProject(EngineInfo engineInfo, ProjectInfo newProject)
        {
            string mainDotCpp = 
                "/*\r\n" +
                "Copyright © from 2024 to present, UNKNOWN STRYKER (Hojin Lee / Joey). All Rights Reserved.\r\n" +
                "\r\n" +
                "Licensed under the Frogman Engine License (the \"License\");\r\n" +
                "you may not use this file except in compliance with the License.\r\n" +
                "You may obtain a copy of the License at\r\n" +
                "\r\n\t" +
                "https://github.com/UnknownStryker-Interactive-Technology/Frogman-Engine-Apache-License/blob/release/LICENSE.md\r\n" +
                "\r\n" +
                "Unless required by applicable law or agreed to in writing, software\r\n" +
                "distributed under the License is distributed on an \"AS IS\" BASIS,\r\n" +
                "WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.\r\n" +
                "See the License for the specific language governing permissions and\r\n" +
                "limitations under the License.\r\n" +
                "*/\r\n" +
                "#include <FE/framework.hxx>\r\n" +
                "#include <FE/engine.hpp>\r\n" +
                "FROGMAN_ENGINE();";


            Debug.Assert(string.IsNullOrEmpty(newProject.ProjectPath) is false, "Project path is null or empty.");
            string pathToAssetsFolder = System.IO.Path.Combine(newProject.ProjectPath, "Assets");
            string pathToCMakeFolder = System.IO.Path.Combine(newProject.ProjectPath, "CMake");
            string pathToIncludeFolder = System.IO.Path.Combine(newProject.ProjectPath, "Include");
            string pathToSourceFolder = System.IO.Path.Combine(newProject.ProjectPath, "Source");
            string pathToBinariesFolder = System.IO.Path.Combine(newProject.ProjectPath, "Binaries");

            Directory.CreateDirectory(newProject.ProjectPath);
            Directory.CreateDirectory(pathToBinariesFolder);
            Directory.CreateDirectory(pathToAssetsFolder);
            Directory.CreateDirectory(pathToCMakeFolder);
            Directory.CreateDirectory(pathToIncludeFolder);
            Directory.CreateDirectory(pathToSourceFolder);




            EditortimeFroggy editortimeFroggy = new EditortimeFroggy
            {
                EngineInfo = engineInfo,
                ProjectInfo = newProject,
                ProjectConfig = new ()
            };
            string jsonFlavoredFroggy = System.Text.Json.JsonSerializer.Serialize<EditortimeFroggy>(editortimeFroggy, new System.Text.Json.JsonSerializerOptions { WriteIndented = true });
            string froggyFileName = newProject.ProjectName + ".froggy";
            string froggyFilePath = System.IO.Path.Combine(newProject.ProjectPath, froggyFileName);
            File.WriteAllText(froggyFilePath, jsonFlavoredFroggy);




            Debug.Assert(string.IsNullOrEmpty(engineInfo.InstallationPath) is false, "Engine installation path is null or empty.");
            string ProjectAssetFolderSourceDir = Path.Combine(Path.Combine(engineInfo.InstallationPath, "Launcher-Script"), "Assets");

            // Generate the CMakeLists.txt and run the CMake to generate the project files. ${YOUR_PROJECT_NAME} ${TARGET_FE_GDK_PATH}
            string? cmakeListsTxt;
            string buildDotBatFile = File.ReadAllText(System.IO.Path.Combine(ProjectAssetFolderSourceDir, "build.bat"));
            File.WriteAllText(System.IO.Path.Combine(pathToCMakeFolder, "build.bat"), buildDotBatFile);

            string buildWithVs2022BatFile = File.ReadAllText(System.IO.Path.Combine(ProjectAssetFolderSourceDir, "build-with-vs2022.bat"));
            File.WriteAllText(System.IO.Path.Combine(pathToCMakeFolder, "build-with-vs2022.bat"), buildWithVs2022BatFile);

            string buildWithVs2026BatFile = File.ReadAllText(System.IO.Path.Combine(ProjectAssetFolderSourceDir, "build-with-vs2026.bat"));
            File.WriteAllText(System.IO.Path.Combine(pathToCMakeFolder, "build-with-vs2026.bat"), buildWithVs2026BatFile);

            File.WriteAllText(System.IO.Path.Combine(pathToCMakeFolder, ".gitignore"), "Solution_X64_AVX/\r\nSolution_X64_AVX512F/", System.Text.Encoding.UTF8);




            cmakeListsTxt = File.ReadAllText(System.IO.Path.Combine(ProjectAssetFolderSourceDir, "CMakeListsTemplateForGame.txt"));
            Debug.Assert(string.IsNullOrEmpty(newProject.ProjectName) == false, "Project name is null or empty");
            cmakeListsTxt = cmakeListsTxt.Replace("${YOUR_PROJECT_NAME}", newProject.ProjectName.Trim());
            cmakeListsTxt = cmakeListsTxt.Replace("${TARGET_FE_GDK_PATH}", engineInfo.InstallationPath);
            cmakeListsTxt = cmakeListsTxt.Replace("\\", "/");

            File.WriteAllText(System.IO.Path.Combine(pathToCMakeFolder, "CMakeLists.txt"), cmakeListsTxt);
            File.WriteAllText(System.IO.Path.Combine(pathToCMakeFolder, "generated.cpp"), String.Empty, System.Text.Encoding.UTF8);
            File.WriteAllText(System.IO.Path.Combine(pathToCMakeFolder, "main.cpp"), mainDotCpp, System.Text.Encoding.UTF8);

            string iconFolder = System.IO.Path.Combine(pathToAssetsFolder, "Icon");
            Directory.CreateDirectory(iconFolder);
            File.Copy(System.IO.Path.Combine(ProjectAssetFolderSourceDir, "runtime icon.png"), System.IO.Path.Combine(iconFolder, "runtime icon.png"));

            string videoFolder = System.IO.Path.Combine(pathToAssetsFolder, "Video");
            Directory.CreateDirectory(videoFolder);
            File.Copy(System.IO.Path.Combine(ProjectAssetFolderSourceDir, "runtime splash video 1.mp4"), System.IO.Path.Combine(videoFolder, "runtime splash video 1.mp4"));
            File.Copy(System.IO.Path.Combine(ProjectAssetFolderSourceDir, "runtime splash video 2.mp4"), System.IO.Path.Combine(videoFolder, "runtime splash video 2.mp4"));

            Directory.CreateDirectory(System.IO.Path.Combine(pathToAssetsFolder, "Shaders"));

            string splashFolder = System.IO.Path.Combine(pathToAssetsFolder, "Splash");
            Directory.CreateDirectory(splashFolder);
            File.Copy(System.IO.Path.Combine(ProjectAssetFolderSourceDir, "Shader Compile Splash.png"), System.IO.Path.Combine(splashFolder, "Shader Compile Splash.png"));
            File.Copy(System.IO.Path.Combine(ProjectAssetFolderSourceDir, "Shader Compile Splash 2.png"), System.IO.Path.Combine(splashFolder, "Shader Compile Splash 2.png"));
            File.Copy(System.IO.Path.Combine(ProjectAssetFolderSourceDir, "Shader Compile Splash 3.png"), System.IO.Path.Combine(splashFolder, "Shader Compile Splash 3.png"));
        }
        public override void CreateCommandLineInterfaceAppProject(EngineInfo engineInfo, ProjectInfo newProject)
        {
            // Add implementation here
        }
        public override void CreateStaticLibraryProject(EngineInfo engineInfo, ProjectInfo newProject)
        {
            // Add implementation here
        }
        public override void CreateDynamicLibraryProject(EngineInfo engineInfo, ProjectInfo newProject)
        {
            // Add implementation here
        }
    }
}
