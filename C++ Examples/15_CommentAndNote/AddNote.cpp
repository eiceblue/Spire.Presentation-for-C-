#include "pch.h"

using namespace std;
using namespace Spire::Presentation;

int main()
{
	std::wstring inputFile = DataPath"AddNote.pptx";
	std::wstring outputFile = OutputPath"AddNote.pptx";

	//Create a PPT document
	Presentation* ppt = new Presentation();
	//Load the file from disk.
	ppt->LoadFromFile(inputFile.c_str());

	ISlide* slide = ppt->GetSlides()->GetItem(0);

	//Add note slide
	NotesSlide* notesSlide = slide->AddNotesSlide();

	//Add paragraph in the notesSlide
	TextParagraph* paragraph = new TextParagraph();
	paragraph->SetText(L"Tips for making effective presentations:");
	notesSlide->GetNotesTextFrame()->GetParagraphs()->Append(paragraph);

	paragraph = new TextParagraph();
	paragraph->SetText(L"Use the slide master feature to create a consistent and simple design template.");
	notesSlide->GetNotesTextFrame()->GetParagraphs()->Append(paragraph);
	//Set the bullet type for the paragraph in notesSlide
	notesSlide->GetNotesTextFrame()->GetParagraphs()->GetItem(1)->SetBulletType(TextBulletType::Numbered);
	notesSlide->GetNotesTextFrame()->GetParagraphs()->GetItem(1)->SetBulletStyle(NumberedBulletStyle::BulletArabicPeriod);

	paragraph = new TextParagraph();
	paragraph->SetText(L"Simplify and limit the number of words on each screen.");
	notesSlide->GetNotesTextFrame()->GetParagraphs()->Append(paragraph);
	//Set the bullet type for the paragraph in notesSlide
	notesSlide->GetNotesTextFrame()->GetParagraphs()->GetItem(2)->SetBulletType(TextBulletType::Numbered);
	notesSlide->GetNotesTextFrame()->GetParagraphs()->GetItem(2)->SetBulletStyle(NumberedBulletStyle::BulletArabicPeriod);

	paragraph = new TextParagraph();
	paragraph->SetText(L"Use contrasting colors for text and background.");
	notesSlide->GetNotesTextFrame()->GetParagraphs()->Append(paragraph);
	//Set the bullet type for the paragraph in notesSlide
	notesSlide->GetNotesTextFrame()->GetParagraphs()->GetItem(3)->SetBulletType(TextBulletType::Numbered);
	notesSlide->GetNotesTextFrame()->GetParagraphs()->GetItem(3)->SetBulletStyle(NumberedBulletStyle::BulletArabicPeriod);

	//Save to file.
	ppt->SaveToFile(outputFile.c_str(), FileFormat::Pptx2013);
	delete ppt;
}
