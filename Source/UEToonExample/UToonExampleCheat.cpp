// Fill out your copyright notice in the Description page of Project Settings.
#include "UToonExampleCheat.h"


#include "GenericPlatform/GenericPlatformProcess.h"
#include "Tasks/Task.h"


void UUToonExampleCheat::LaunchTest01()
{
	UE::Tasks::Launch(
		UE_SOURCE_LOCATION,
		[]
		{
			UE_LOG(LogTemp, Log, TEXT("LaunchTest01!"));
		}
	);
}

void UUToonExampleCheat::LaunchTest02()
{
	UE::Tasks::FTaskEvent Event{ UE_SOURCE_LOCATION };
	UE::Tasks::FTask Task = UE::Tasks::Launch(
		UE_SOURCE_LOCATION, 
		[]
		{
			UE_LOG(LogTemp, Log, TEXT("Task Started!"));

			FPlatformProcess::Sleep(1.f);

			UE_LOG(LogTemp, Log, TEXT("Task Finished!"));
		}, Event);

	UE_LOG(LogTemp, Log, TEXT("LaunchTest02!"));
	Event.Trigger();
}

void UUToonExampleCheat::LaunchTest03()
{
	UE::Tasks::FTaskEvent EventMother{ UE_SOURCE_LOCATION };
	UE::Tasks::FTask TaskMother = UE::Tasks::Launch(
		UE_SOURCE_LOCATION,
		[]
		{
			UE_LOG(LogTemp, Log, TEXT("Event Mother Finished!"));
		}, EventMother);

	UE::Tasks::FTaskEvent Event11{ UE_SOURCE_LOCATION };
	UE::Tasks::FTask Task11 = UE::Tasks::Launch(
		UE_SOURCE_LOCATION,
		[]
		{
			UE_LOG(LogTemp, Log, TEXT("Event11"));
		}, Event11);

	UE::Tasks::FTaskEvent Event12{ UE_SOURCE_LOCATION };
	UE::Tasks::FTask Task12 = UE::Tasks::Launch(
		UE_SOURCE_LOCATION,
		[]
		{
			UE_LOG(LogTemp, Log, TEXT("Event12"));
		}, Event12);

	UE::Tasks::FTaskEvent Event21{ UE_SOURCE_LOCATION };
	UE::Tasks::FTask Task21 = UE::Tasks::Launch(
		UE_SOURCE_LOCATION,
		[]
		{
			UE_LOG(LogTemp, Log, TEXT("Eent21"));
		}, Event21);

	UE_LOG(LogTemp, Log, TEXT("=== LaunchTest03 ==="));

	Event12.AddPrerequisites(Event11);
	EventMother.AddPrerequisites(Event12);
	EventMother.AddPrerequisites(Event21);
	EventMother.Trigger();

	Event21.Trigger();

	Event12.Trigger();
	Event11.Trigger();

	// 이벤트 그래프
	//
	// Event11 - Event12 - EventMother
	// Event21 ----------/


	// 태스크 그래프의 경우에 알아서 전부 태스크들을 실행해주는게 아님.
	// 태스크마다 Trigger는 다 따로 해줘야되며 Trigger가 기록이 됐는 태스크의 경우에 PreReq가 완료됐다는 이벤트가 오면 알아서 실행됨.
}

void UUToonExampleCheat::ParallelForTest01()
{
	TArray<int64> Arr;
	Arr.AddZeroed(50);

	int64 Acc = 0;

	ParallelForTemplate(Arr.Num(), [&Arr, &Acc](int32 Index)
		{
			Acc++;

			for (int64 i=0;i<100000000;i++)
			{
				Arr[Index] += Acc;
			}
		});


	int32 a = 0;
}
