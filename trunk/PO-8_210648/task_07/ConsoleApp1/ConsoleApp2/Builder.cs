namespace ConsoleApp2;

public abstract class Builder
{
    public abstract void BuildEyes();
    public abstract void BuildNose();
    public abstract void BuildMouth();
    public abstract void BuildEars();
    public abstract void BuildHair();
    
    public abstract Product GetResult();
}