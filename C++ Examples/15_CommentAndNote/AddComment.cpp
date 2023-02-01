#include "pch.h"

using namespace std;
using namespace Spire::Presentation;

int main()
{
	std::wstring inputFile = DataPath"AddComment.pptx";
	std::wstring outputFile = OutputPath"AddComment.pptx";

	//Create a PPT document
	Presentation* ppt = new Presentation();
	//Load the file from disk.
	ppt->LoadFromFile(inputFile.c_str());

	//Comment author
	ICommentAuthor* author = ppt->GetCommentAuthors()->AddAuthor(L"E-iceblue", L"comment:");

	//Add comment
	ppt->GetSlides()->GetItem(0)->AddComment(author, L"Add comment", new PointF(18, 25), DateTime::GetNow());

	//Save to file.
	ppt->SaveToFile(outputFile.c_str(), FileFormat::Pptx2013);
	delete ppt;
}
