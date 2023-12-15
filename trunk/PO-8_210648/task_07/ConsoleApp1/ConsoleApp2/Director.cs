namespace ConsoleApp2;

public class Director
{
    private Builder _bilder;

    public Director(Builder builder)
    {
        _bilder = builder;
    }

    public Product Construct()
    {
        _bilder.BuildEyes();
        _bilder.BuildNose();
        _bilder.BuildMouth();
        _bilder.BuildEars();
        _bilder.BuildHair();
        return _bilder.GetResult();
    }
}