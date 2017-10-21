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

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#if PLATFORM_ANDROID
#include "../../../Launch/Public/Android/AndroidJNI.h"
#endif
#include "SpeakMyWordsBP.generated.h"

/**
 * 
 */
UCLASS()
class SPEAKMYWORDS_API USpeakMyWordsBP : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	//This function is fo initializing the Android's Text To Speech service in Java.
	UFUNCTION(BlueprintCallable, Category = SpeakMyWords)
		static void InitSpeakMywords();

	//This function is to speak this sentence.
	UFUNCTION(BlueprintCallable, Category = SpeakMyWords)
		static void SpeakThisSentence(FString Sentence);

	//This function is to set the pitch rate of speaking.
	UFUNCTION(BlueprintCallable, Category = SpeakMyWords)
		static void SetSpeakingPitch(float pitch);

	//This function is to set the speech rate.
	UFUNCTION(BlueprintCallable, Category = SpeakMyWords)
		static void SetSpeakingSpeechRate(float rate);

	//This function is get to know whether it's currenlty speaking or not.
	UFUNCTION(BlueprintPure, Category = SpeakMyWords)
		static bool IsSpeaking();


	//This function is get to know whether speaking is initialized or not.
	UFUNCTION(BlueprintPure, Category = SpeakMyWords)
		static bool IsSpeakingInitialized();

	//This function is to speaking language to device default language.
	UFUNCTION(BlueprintCallable, Category = SpeakMyWords)
		static void SetToDeviceDefaultlanguage();

#if PLATFORM_ANDROID
	static jmethodID ActivityMethod_InitSpeakMyWords;
	static jmethodID ActivityMethod_SpeakThisSentence;
	static jmethodID ActivityMethod_SetSpeakingPitch;
	static jmethodID ActivityMethod_SetSpeakingSpeechRate;
	static jmethodID ActivityMethod_IsSpeaking;
	static jmethodID ActivityMethod_SetDefaultLanguage;
	static jmethodID ActivityMethod_IsSpeakingInitialized;
#endif
	
	
	
};
