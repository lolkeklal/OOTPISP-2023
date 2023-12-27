namespace ConsoleApp2;

public class GoodFaceBuilder : Builder
{
    private Product _product = new Product();

    public override void BuildEyes()
    {
        _product.AddEyes(new string[]{"good","blue"});
    }

    public override void BuildNose()
    {
        _product.AddNose(new string[]{"good","blue"});
    }

    public override void BuildMouth()
    {
        _product.AddMouth(new string[]{"good","blue"});
    }

    public override void BuildEars()
    {
        _product.AddEars(new string[]{"good","blue"});
    }

    public override void BuildHair()
    {
        _product.AddHair(new string[]{"good","blue"});
    }

    public override Product GetResult()
    {
        return _product;
    }
}