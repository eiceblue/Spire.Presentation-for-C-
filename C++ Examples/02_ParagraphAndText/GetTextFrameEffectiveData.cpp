#include "pch.h"

using namespace std;
using namespace Spire::Presentation;

const wstring textTypeToString(TextAnchorType textType)
{
	switch (textType)
	{
	case Spire::Presentation::TextAnchorType::None:
		return L"None";
		break;
	case Spire::Presentation::TextAnchorType::Top:
		return L"Top";
		break;
	case Spire::Presentation::TextAnchorType::Center:
		return L"Center";
		break;
	case Spire::Presentation::TextAnchorType::Bottom:
		return L"Bottom";
		break;
	case Spire::Presentation::TextAnchorType::Justified:
		return L"Justified";
		break;
	case Spire::Presentation::TextAnchorType::Distributed:
		return L"Distributed";
		break;
	case Spire::Presentation::TextAnchorType::Right:
		return L"Right";
		break;
	case Spire::Presentation::TextAnchorType::Left:
		return L"Left";
		break;
	default:
		break;
	}
}
const wstring textFitToString(TextAutofitType  textFit)
{
	switch (textFit)
	{
	case Spire::Presentation::TextAutofitType::UnDefined:
		return L"UnDefined";
		break;
	case Spire::Presentation::TextAutofitType::None:
		return L"None";
		break;
	case Spire::Presentation::TextAutofitType::Normal:
		return L"Normal";
		break;
	case Spire::Presentation::TextAutofitType::Shape:
		return L"Shape";
		break;
	default:
		break;
	}
}

const wstring vertTextToString(VerticalTextType  vertText)
{
	switch (vertText)
	{
	case Spire::Presentation::VerticalTextType::None:
		return L"None";
		break;
	case Spire::Presentation::VerticalTextType::Horizontal:
		return L"Horizontal";
		break;
	case Spire::Presentation::VerticalTextType::Vertical:
		return L"Vertical";
		break;
	case Spire::Presentation::VerticalTextType::Vertical270:
		return L"Vertical270";
		break;
	case Spire::Presentation::VerticalTextType::WordArtVertical:
		return L"WordArtVertical";
		break;
	case Spire::Presentation::VerticalTextType::EastAsianVertical:
		return L"EastAsianVertical";
		break;
	case Spire::Presentation::VerticalTextType::MongolianVertical:
		return L"MongolianVertical";
		break;
	case Spire::Presentation::VerticalTextType::WordArtVerticalRightToLeft:
		return L"WordArtVerticalRightToLeft";
		break;
	default:
		break;
	}
}

int main()
{
	std::wstring inputFile = DataPath"Template_Az1.pptx";
	std::wstring outputFile = OutputPath"GetTextFrameEffectiveData.txt";

	//Create a PPT document
	Presentation* presentation = new Presentation();

	//Load PPT file from disk
	presentation->LoadFromFile(inputFile.c_str());
	//Get the first slide
	ISlide* slide = presentation->GetSlides()->GetItem(0);
	//Get a shape 
	IAutoShape* shape = dynamic_cast<IAutoShape*>(presentation->GetSlides()->GetItem(0)->GetShapes()->GetItem(0));

	ITextFrameProperties* textFrameFormat = shape->GetTextFrame();
	wofstream outFile(outputFile, ios::out);
	outFile << "Anchoring type : " << textTypeToString(textFrameFormat->GetAnchoringType()) << endl;
	outFile << "Autofit type : " << textFitToString(textFrameFormat->GetAutofitType()) << endl;
	outFile << "Text vertical type: " << vertTextToString(textFrameFormat->GetVerticalTextType()) << endl;
	outFile << "Margins " << endl;
	outFile << "   Left: " << textFrameFormat->GetMarginLeft() << endl;
	outFile << "   Top:  " << textFrameFormat->GetMarginTop() << endl;
	outFile << "   Right: " << textFrameFormat->GetMarginRight() << endl;
	outFile << "   Bottom: " << textFrameFormat->GetMarginBottom() << endl;

	outFile.close();
	delete presentation;

}
