#include "pch.h"

using namespace std;
using namespace Spire::Presentation;

int main()
{
	std::wstring inputFile = DataPath"FillShapeWithGradient.pptx";
	std::wstring outputFile = OutputPath"FillShapeWithGradient.pptx";

	//Load a PPT document
	Presentation* ppt = new Presentation();

	ppt->LoadFromFile(inputFile.c_str());

	//Get the first shape and set the style to be Gradient
	IAutoShape* GradientShape = dynamic_cast<IAutoShape*>(ppt->GetSlides()->GetItem(0)->GetShapes()->GetItem(0));
	GradientShape->GetFill()->SetFillType(FillFormatType::Gradient);
	GradientShape->GetFill()->GetGradient()->GetGradientStops()->Append(0, Color::GetLightSkyBlue());
	GradientShape->GetFill()->GetGradient()->GetGradientStops()->Append(1, Color::GetLightGray());

	ppt->SaveToFile(outputFile.c_str(), FileFormat::Pptx2010);
	delete ppt;
}
