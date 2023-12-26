namespace ConsoleApp1;

public class HtmlBuilder : Builder
{
    private Product _product = new Product();
    public override void BuildHeader()
    {
        _product.AddHeader("<");
    }

    public override void BuildBlock()
    {
        _product.AddBlock("h");
    }

    public override void BuildEnding()
    {
        _product.AddEnding(">");
    }

    public override Product GetResult()
    {
        return _product;
    }
}