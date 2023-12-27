namespace ConsoleApp1;

public class XlsBuilder : Builder
{
    private Product _product = new Product();
    public override void BuildHeader()
    {
        _product.AddHeader("Table");
    }

    public override void BuildBlock()
    {
        _product.AddBlock("data");
    }

    public override void BuildEnding()
    {
        _product.AddEnding("Create by");
    }

    public override Product GetResult()
    {
        return _product;
    }
}