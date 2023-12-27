namespace ConsoleApp1;

public abstract class Builder
{
    public abstract void BuildHeader();
    public abstract void BuildBlock();
    public abstract void BuildEnding();
    public abstract Product GetResult();
}