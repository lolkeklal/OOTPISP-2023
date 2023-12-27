using ConsoleApp1;

FabricSingleton fabricSingleton = FabricSingleton.Instance;

CreateAllFigures(fabricSingleton);


TxtBuilder txtbuilder = new TxtBuilder();
XlsBuilder xlsBuilder = new XlsBuilder();
Director directorXls = new Director(xlsBuilder);
Director directorTxt = new Director(txtbuilder);
directorTxt.Construct();
directorXls.Construct();
var product1 = txtbuilder.GetResult();
var product2 = xlsBuilder.GetResult();
Console.WriteLine($"{product1.Header} {product1.Block} {product1.Ending}");
Console.WriteLine($"{product2.Header} {product2.Block} {product2.Ending}");

void CreateAllFigures(Fabric f)
{
    Rectangle rectangle = f.CreateRectangle(1,2);
    Line line = f.CreateLine(6);
    Oval oval = f.CreateOval(10);
    Text text = f.CreateText(4);
    rectangle.Show();
    line.Show();
    oval.Show();
    text.Show();
}