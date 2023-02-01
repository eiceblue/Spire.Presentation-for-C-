#include "pch.h"

using namespace std;
using namespace Spire::Presentation;

int main()
{
	std::wstring inputFile = DataPath"Table.pptx";
	std::wstring outputFile = OutputPath"SetTextFormat.pptx";

	//Create a PPT document
	Presentation* presentation = new Presentation();

	//Load PPT file from disk
	presentation->LoadFromFile(inputFile.c_str());
	//Get the first slide
	ISlide* slide = presentation->GetSlides()->GetItem(0);
	for (int s = 0; s < slide->GetShapes()->GetCount(); s++)
	{
		IShape* shape = slide->GetShapes()->GetItem(s);
		//Verify if it is table
		if (dynamic_cast<ITable*>(shape) != nullptr)
		{
			ITable* table = dynamic_cast<ITable*>(shape);

			Cell* cell1 = table->GetTableRows()->GetItem(0)->GetItem(0);
			//Set table cell's text alignment type 
			cell1->SetTextAnchorType(TextAnchorType::Top);
			//Set italic style
			cell1->GetTextFrame()->GetTextRange()->GetFormat()->SetIsItalic(TriState::True);

			Cell* cell2 = table->GetTableRows()->GetItem(1)->GetItem(0);
			//Set table cell's foreground color
			cell2->GetTextFrame()->GetTextRange()->GetFill()->SetFillType(FillFormatType::Solid);
			cell2->GetTextFrame()->GetTextRange()->GetFill()->GetSolidColor()->SetColor(Color::GetGreen());
			//Set table cell's background color
			cell2->GetFillFormat()->SetFillType(FillFormatType::Solid);
			cell2->GetFillFormat()->GetSolidColor()->SetColor(Color::GetLightGray());


			Cell* cell3 = table->GetTableRows()->GetItem(2)->GetItem(2);
			//Set table cell's font and font size
			cell3->GetTextFrame()->GetTextRange()->SetFontHeight(12);
			cell3->GetTextFrame()->GetTextRange()->SetLatinFont(new TextFont(L"Arial Black"));
			cell3->GetTextFrame()->GetTextRange()->GetHighlightColor()->SetColor(Color::GetYellowGreen());

			Cell* cell4 = table->GetTableRows()->GetItem(2)->GetItem(1);
			//Set table cell's margin and borders
			cell4->SetMarginLeft(20);
			cell4->SetMarginTop(30);
			cell4->GetBorderTop()->SetFillType(FillFormatType::Solid);
			cell4->GetBorderTop()->GetSolidFillColor()->SetColor(Color::GetRed());
			cell4->GetBorderBottom()->SetFillType(FillFormatType::Solid);
			cell4->GetBorderBottom()->GetSolidFillColor()->SetColor(Color::GetRed());
			cell4->GetBorderLeft()->SetFillType(FillFormatType::Solid);
			cell4->GetBorderLeft()->GetSolidFillColor()->SetColor(Color::GetRed());
			cell4->GetBorderRight()->SetFillType(FillFormatType::Solid);
			cell4->GetBorderRight()->GetSolidFillColor()->SetColor(Color::GetRed());
		}
	}
	presentation->SaveToFile(outputFile.c_str(), FileFormat::Pptx2013);
	delete presentation;
}
