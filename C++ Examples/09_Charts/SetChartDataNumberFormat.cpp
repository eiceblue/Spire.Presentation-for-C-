#include "pch.h"

using namespace std;
using namespace Spire::Presentation;

int main()
{
	std::wstring inputFile = DataPath"SetChartDataNumberFormat.pptx";
	std::wstring outputFile = OutputPath"SetChartDataNumberFormat.pptx";

	//Create a PPT document
	Presentation* ppt = new Presentation();
	//Load the file from disk.
	ppt->LoadFromFile(inputFile.c_str());

	//Get the chart.
	IChart* chart = dynamic_cast<IChart*>(ppt->GetSlides()->GetItem(0)->GetShapes()->GetItem(0));

	//Set the number format for Axis
	chart->GetPrimaryValueAxis()->SetNumberFormat(L"#,##0.00");

	//Set the DataLabels format for Axis
	chart->GetSeries()->GetItem(0)->GetDataLabels()->SetLabelValueVisible(true);
	chart->GetSeries()->GetItem(0)->GetDataLabels()->SetPercentValueVisible(false);
	chart->GetSeries()->GetItem(0)->GetDataLabels()->SetNumberFormat(L"#,##0.00");
	chart->GetSeries()->GetItem(0)->GetDataLabels()->SetHasDataSource(false);

	//Set the number format for ChartData
	for (int i = 1; i <= chart->GetSeries()->GetItem(0)->GetValues()->GetCount(); i++)
	{
		chart->GetChartData()->GetItem(i, 1)->SetNumberFormat(L"#,##0.00");
	}

	//Save to file.
	ppt->SaveToFile(outputFile.c_str(), FileFormat::Pptx2013);
	delete ppt;
}
