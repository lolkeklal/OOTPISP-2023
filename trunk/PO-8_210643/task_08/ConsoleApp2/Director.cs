namespace ConsoleApp1;

public class Director
{
    private readonly Builder _bilder;

    public Director(Builder builder)
    {
        _bilder = builder;
    }

    public void Construct()
    {
        _bilder.BuildHeader();
        _bilder.BuildBlock();
        _bilder.BuildEnding();
    }
}

