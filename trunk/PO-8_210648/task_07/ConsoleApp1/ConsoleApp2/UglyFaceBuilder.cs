namespace ConsoleApp2;

public class UglyFaceBuilder : Builder
{
    private Product _product = new Product();

    public override void BuildEyes()
    {
        _product.AddEyes(new string[]{"ugly","red"});
    }

    public override void BuildNose()
    {
        _product.AddNose(new string[]{"ugly","red"});
    }

    public override void BuildMouth()
    {
        _product.AddMouth(new string[]{"ugly","red"});
    }

    public override void BuildEars()
    {
        _product.AddEars(new string[]{"ugly","red"});
    }

    public override void BuildHair()
    {
        _product.AddHair(new string[]{"ugly","red"});
    }

    public override Product GetResult()
    {
        return _product;
    }
}