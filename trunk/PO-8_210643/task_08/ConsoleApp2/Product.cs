namespace ConsoleApp1;

public class Product
{
    private object _header;
    private object _block;
    private object _ending;
    
    public object Header => _header;
    public object Block => _block; 
    public object Ending => _ending; 

    public void AddHeader(object header)
    {
        _header = header;
    }

    public void AddBlock(object block)
    {
        _block = block;
    }

    public void AddEnding(object ending)
    {
        _ending = ending;
    }
    
}