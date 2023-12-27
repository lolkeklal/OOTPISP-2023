namespace ConsoleApp1;

public class TxtBuilder : Builder
{
    private Product _product = new Product();
    public override void BuildHeader()
    {
        _product.AddHeader("Header");
    }

    public override void BuildBlock()
    {
        _product.AddBlock("text");
    }

    public override void BuildEnding()
    {
        _product.AddEnding("\\n");
    }

    public override Product GetResult()
    {
        return _product;
    }
}