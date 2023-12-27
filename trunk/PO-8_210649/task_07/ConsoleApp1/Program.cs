
using ConsoleApp1;

Fabric fabric = new Fabric();

BeautifulFabric beautifulFabric = new BeautifulFabric();

FabricPrototype fabricPrototype = new FabricPrototype(new BeautifulRectangle(1, 2), new BeautifulLine(6),
    new BeatifulOval(10), new BeautifulText(4));

CreateAllFigures(fabric);
CreateAllFigures(beautifulFabric);
CreateAllFigures(fabricPrototype);

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