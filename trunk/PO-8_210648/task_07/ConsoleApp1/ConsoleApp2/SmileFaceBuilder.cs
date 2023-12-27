namespace ConsoleApp2;

public class SmileFaceBuilder : Builder
{
    private Product _product = new Product();

    public override void BuildEyes()
    {
        _product.AddEyes(new string[]{"smile","green"});
    }

    public override void BuildNose()
    {
        _product.AddNose(new string[]{"smile","green"});
    }

    public override void BuildMouth()
    {
        _product.AddMouth(new string[]{"smile","green"});
    }

    public override void BuildEars()
    {
        _product.AddEars(new string[]{"smile","green"});
    }

    public override void BuildHair()
    {
        _product.AddHair(new string[]{"smile","green"});
    }

    public override Product GetResult()
    {
        return _product;
    }
}