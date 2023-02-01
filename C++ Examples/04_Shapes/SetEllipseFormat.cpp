#include "pch.h"

using namespace std;
using namespace Spire::Presentation;

int main()
{
	std::wstring outputFile = OutputPath"SetEllipseFormat.pptx";

	//Create a PPT document
	Presentation* presentation = new Presentation();

	//Get the first slide
	ISlide* slide = presentation->GetSlides()->GetItem(0);

	//Add a rectangle
	RectangleF* rect = new RectangleF(presentation->GetSlideSize()->GetSize()->GetWidth() / 2 - 100, 100, 200, 100);
	IAutoShape* shape = slide->GetShapes()->AppendShape(ShapeType::Ellipse, rect);

	//Set the fill format of shape
	shape->GetFill()->SetFillType(FillFormatType::Solid);
	shape->GetFill()->GetSolidColor()->SetColor(Color::GetCadetBlue());

	//Set the fill format of line
	shape->GetLine()->SetFillType(FillFormatType::Solid);
	shape->GetLine()->GetSolidFillColor()->SetColor(Color::GetDimGray());

	//Save the document
	presentation->SaveToFile(outputFile.c_str(), FileFormat::Pptx2013);
	delete presentation;
}
