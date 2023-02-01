#include "pch.h"

using namespace std;
using namespace Spire::Presentation;

int main()
{
	std::wstring inputFile = DataPath"Properties.pptx";
	std::wstring outputFile = OutputPath"Properties.pptx";

	//Create a PPT document
	Presentation* presentation = new Presentation();
	presentation->LoadFromFile(inputFile.c_str());

	//Set the DocumentProperty of PPT document
	presentation->GetDocumentProperty()->SetApplication(L"Spire.Presentation");
	presentation->GetDocumentProperty()->SetAuthor(L"E-iceblue");
	presentation->GetDocumentProperty()->SetCompany(L"E-iceblue Co., Ltd.");
	presentation->GetDocumentProperty()->SetKeywords(L"Demo File");
	presentation->GetDocumentProperty()->SetComments(L"This file is used to test Spire.Presentation.");
	presentation->GetDocumentProperty()->SetCategory(L"Demo");
	presentation->GetDocumentProperty()->SetTitle(L"This is a demo file.");
	presentation->GetDocumentProperty()->SetSubject(L"Test");

	//Save the document
	presentation->SaveToFile(outputFile.c_str(), FileFormat::Pptx2010);
	delete presentation;

}
