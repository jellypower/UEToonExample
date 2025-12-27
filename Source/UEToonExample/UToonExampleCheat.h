// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/CheatManager.h"

#include "UToonExampleCheat.generated.h"

/**
 * 
 */
UCLASS()
class UETOONEXAMPLE_API UUToonExampleCheat : public UCheatManager
{
	GENERATED_BODY()

private:
	UFUNCTION(exec, BlueprintCallable, Category = "Cheat Manager")
	virtual void LaunchTest01();

	UFUNCTION(exec, BlueprintCallable, Category = "Cheat Manager")
	virtual void LaunchTest02();

	UFUNCTION(exec, BlueprintCallable, Category = "Cheat Manager")
	virtual void LaunchTest03();

	UFUNCTION(exec, BlueprintCallable, Category = "Cheat Manager")
	virtual void ParallelForTest01();
};


