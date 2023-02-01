#include "pch.h"

using namespace std;
using namespace Spire::Presentation;

int main()
{
	std::wstring inputFile = DataPath"ChangeSlidePosition.pptx";
	std::wstring outputFile = OutputPath"IndividualSlideToHtml.html";

	//Create a PPT document
	Presentation* ppt = new Presentation();
	//Load the file from disk.
	ppt->LoadFromFile(inputFile.c_str());

	//Get the first slide
	ISlide* slide = ppt->GetSlides()->GetItem(0);

	//Save the first slide to HTML 
	slide->SaveToFile(outputFile.c_str(), FileFormat::Html);

	delete ppt;
}
