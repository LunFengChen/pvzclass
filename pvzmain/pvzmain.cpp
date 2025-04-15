#include "../pvzclass/pvzclass.h"
#include "../pvzclass/Events/Events.h"
#include "../pvzclass/Extensions.h"

int main()
{
	DWORD pid = ProcessOpener::Open();
	if (!pid) return 1;
	PVZ::InitPVZ(pid);
	
	if(PVZ::GetBoard().GetBaseAddress() != 0){
		while(true){
			std::string s;
			std::cin >> s;

			if (!s.compare("1")) {
				EnablePortal();
				continue;
			}
			else if (!s.compare("2")) {
				EnablePortal(ThreeState::Enable);
				Creator::AsmInit();
				Creator::CreatePortal(3, 5, 4, 0, 0, 1, 0, 5);
				Creator::AsmReset();
				continue;
			}
			else if (!s.compare("3")) {
				EnablePortal(ThreeState::Disable);
				continue;
			}
		}
	}

	PVZ::QuitPVZ();
	return 0;
}
