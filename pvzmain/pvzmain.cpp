#include "../pvzclass/pvzclass.h"
#include "../pvzclass/Events/Events.h"
#include "../pvzclass/Extensions.h"

int main()
{
	DWORD pid = ProcessOpener::Open();
	if (!pid) return 1;
	PVZ::InitPVZ(pid);

	std::string caption_str = "123restart";
	Creator::CreateCaption(caption_str.c_str(), 11, CaptionStyle::Lowermiddle);
	caption_str = "123";
	Creator::CreateCaption(caption_str.c_str(), 4, CaptionStyle::BottomWhite);

	Sleep(6000);
	std::string str1 = "123restart";
	Creator::CreateCaption(str1.c_str(), str1.size(), CaptionStyle::Lowermiddle);
	std::string str2 = "123";
	Creator::CreateCaption(str2.c_str(), str2.size(), CaptionStyle::Lowermiddle);


	Sleep(6000);
	std::string str3 = "123restart";
	Creator::CreateCaption(str3.c_str(), str3.size()+1, CaptionStyle::Lowermiddle);
	std::string str4 = "123";
	Creator::CreateCaption(str4.c_str(), str4.size()+1, CaptionStyle::Lowermiddle);


	Sleep(6000);
	const char str5[] = "123restart\0";
	Creator::CreateCaption(str5, 13, CaptionStyle::Lowermiddle);

	const char str6[] = { '1', '2', '3', '\0' };
	Creator::CreateCaption(str6, 4, CaptionStyle::Lowermiddle);

	PVZ::QuitPVZ();
	return 0;
}
