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
#include "GameFramework/Actor.h"
#if PLATFORM_ANDROID
	#include "../../../Launch/Public/Android/AndroidJNI.h"
#endif

#include "SpeakingActor.generated.h"

UCLASS(Blueprintable, BlueprintType)
class SPEAKMYWORDS_API ASpeakingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpeakingActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//This function is fo initializing the Android's Text To Speech service in Java.
	UFUNCTION(BlueprintCallable, Category = SpeakMyWords)
		void InitSpeakMywords();

	//This function is to speak this sentence.
	UFUNCTION(BlueprintCallable, Category = SpeakMyWords)
		void SpeakThisSentence(FString Sentence);

	//This function is to set the pitch rate of speaking.
	UFUNCTION(BlueprintCallable, Category = SpeakMyWords)
		void SetSpeakingPitch(float pitch);

	//This function is to set the speech rate.
	UFUNCTION(BlueprintCallable, Category = SpeakMyWords)
		void SetSpeakingSpeechRate(float rate);

	//This function is get to know whether it's currenlty speaking or not.
	UFUNCTION(BlueprintPure, Category = SpeakMyWords)
		bool IsSpeaking();	


	//This function is get to know whether speaking is initialized or not.
	UFUNCTION(BlueprintPure, Category = SpeakMyWords)
		bool IsSpeakingInitialized();

	//This function is to speaking language to device default language.
	UFUNCTION(BlueprintCallable, Category = SpeakMyWords)
		void SetToDeviceDefaultlanguage();

#if PLATFORM_ANDROID
private:
	jmethodID ActivityMethod_InitSpeakMyWords;
	jmethodID ActivityMethod_SpeakThisSentence;
	jmethodID ActivityMethod_SetSpeakingPitch;
	jmethodID ActivityMethod_SetSpeakingSpeechRate;
	jmethodID ActivityMethod_IsSpeaking;
	jmethodID ActivityMethod_SetDefaultLanguage;
	jmethodID ActivityMethod_IsSpeakingInitialized;
#endif

};
