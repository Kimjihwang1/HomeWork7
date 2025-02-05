#include "JihwangGameMode.h"
#include "jihwang_HPawn.h"
#include "JiHwang_PlayerController.h"

AJihwangGameMode::AJihwangGameMode()
{
	DefaultPawnClass = Ajihwang_HPawn::StaticClass();
	PlayerControllerClass = AJiHwang_PlayerController::StaticClass();

}