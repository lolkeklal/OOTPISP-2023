namespace ConsoleApp1;

public class DocBuilder : Builder
{
    private readonly Product _product = new Product();
    public override void BuildHeader()
    {
        _product.AddHeader("Document");
    }

    public override void BuildBlock()
    {
        _product.AddBlock("data");
    }

    public override void BuildEnding()
    {
        _product.AddEnding("Created by Sasha");
    }

    public override Product GetResult()
    {
        return _product;
    }
}