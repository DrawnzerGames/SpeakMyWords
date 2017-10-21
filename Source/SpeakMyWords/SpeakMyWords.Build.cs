/**
* Copyright(c) 2017 DRAWNZER GAMES -> ANURAG
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
*              coolanuragdzxj@gmail.com
*
*/

using UnrealBuildTool;
using System.IO;
using System;

public class SpeakMyWords : ModuleRules
{
	public SpeakMyWords(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				"SpeakMyWords/Public"
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				"SpeakMyWords/Private",
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);

        //Load the Android UPL file for the Speak My Words UE4 Plugin for Android Platform.
        if (Target.Platform == UnrealTargetPlatform.Android)
        {
            Console.WriteLine("Android Modification for Speak My Words UE4 Plugin");
            string PluginPath = Path.Combine(ModuleDirectory, "SpeakMyWords_UPL.xml");
            AdditionalPropertiesForReceipt.Add(new ReceiptProperty("AndroidPlugin", PluginPath));    
        }

    }
}
