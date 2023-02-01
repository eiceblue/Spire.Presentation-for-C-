﻿#include "pch.h"

using namespace std;
using namespace Spire::Presentation;

int main()
{
	std::wstring outputFile = OutputPath"SetTextDirection.pptx";

	//Create an instance of presentation document
	Presentation* ppt = new Presentation();

	//Append a shape with text to the first slide
	IAutoShape* textboxShape = ppt->GetSlides()->GetItem(0)->GetShapes()->AppendShape(ShapeType::Rectangle, new RectangleF(250, 70, 100, 400));
	textboxShape->GetShapeStyle()->GetLineColor()->SetColor(Color::GetTransparent());
	textboxShape->GetFill()->SetFillType(FillFormatType::Solid);
	textboxShape->GetFill()->GetSolidColor()->SetColor(Color::GetLightBlue());
	textboxShape->GetTextFrame()->SetText(L"You Are Welcome Here");
	//Set the text direction to vertical
	textboxShape->GetTextFrame()->SetVerticalTextType(VerticalTextType::Vertical);

	//Append another shape with text to the slide
	textboxShape = ppt->GetSlides()->GetItem(0)->GetShapes()->AppendShape(ShapeType::Rectangle, new RectangleF(350, 70, 100, 400));
	textboxShape->GetShapeStyle()->GetLineColor()->SetColor(Color::GetTransparent());
	textboxShape->GetFill()->SetFillType(FillFormatType::Solid);
	textboxShape->GetFill()->GetSolidColor()->SetColor(Color::GetLightGray());
	//Append some asian characters
	textboxShape->GetTextFrame()->SetText(L"欢迎光临");
	//Set the VerticalTextType as EastAsianVertical to aviod rotating text 90 degrees
	textboxShape->GetTextFrame()->SetVerticalTextType(VerticalTextType::EastAsianVertical);

	//Save the document
	ppt->SaveToFile(outputFile.c_str(), FileFormat::Pptx2013);
	delete ppt;

}
