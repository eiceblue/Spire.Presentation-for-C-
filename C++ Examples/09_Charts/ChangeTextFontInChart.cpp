
#include "pch.h"

using namespace std;
using namespace Spire::Presentation;

int main()
{
	std::wstring inputFile = DataPath"ChangeTextFontInChart.pptx";
	std::wstring outputFile = OutputPath"ChangeTextFontInChart.pptx";

	//Create a PPT document
	Presentation* presentation = new Presentation();
	//Load the file from disk.
	presentation->LoadFromFile(inputFile.c_str());

	//Get chart on the first slide
	IChart* chart = dynamic_cast<IChart*>(presentation->GetSlides()
		->GetItem(0)->GetShapes()->GetItem(0));

	//Change the font of title
	chart->GetChartTitle()->GetTextProperties()->GetParagraphs()->GetItem(0)->GetDefaultCharacterProperties()->SetLatinFont(new TextFont(L"Lucida Sans Unicode"));
	chart->GetChartTitle()->GetTextProperties()->GetParagraphs()->GetItem(0)->GetDefaultCharacterProperties()->GetFill()->GetSolidColor()->SetKnownColor(KnownColors::Blue);
	chart->GetChartTitle()->GetTextProperties()->GetParagraphs()->GetItem(0)->GetDefaultCharacterProperties()->SetFontHeight(30);

	//Change the font of legend
	chart->GetChartLegend()->GetTextProperties()->GetParagraphs()->GetItem(0)->GetDefaultCharacterProperties()->GetFill()->GetSolidColor()->SetKnownColor(KnownColors::DarkGreen);
	chart->GetChartLegend()->GetTextProperties()->GetParagraphs()->GetItem(0)->GetDefaultCharacterProperties()->SetLatinFont(new TextFont(L"Lucida Sans Unicode"));

	//Change the font of series
	chart->GetPrimaryCategoryAxis()->GetTextProperties()->GetParagraphs()->GetItem(0)->GetDefaultCharacterProperties()->GetFill()->GetSolidColor()->SetKnownColor(KnownColors::Red);
	chart->GetPrimaryCategoryAxis()->GetTextProperties()->GetParagraphs()->GetItem(0)->GetDefaultCharacterProperties()->GetFill()->SetFillType(FillFormatType::Solid);
	chart->GetPrimaryCategoryAxis()->GetTextProperties()->GetParagraphs()->GetItem(0)->GetDefaultCharacterProperties()->SetFontHeight(10);
	chart->GetPrimaryCategoryAxis()->GetTextProperties()->GetParagraphs()->GetItem(0)->GetDefaultCharacterProperties()->SetLatinFont(new TextFont(L"Lucida Sans Unicode"));

	//Save to file.
	presentation->SaveToFile(outputFile.c_str(), FileFormat::Pptx2010);
	delete presentation;
}
