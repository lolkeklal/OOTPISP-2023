using Lab_08.Builders;
using Lab_08.Creators;

namespace Lab_08.Directors;

public class AdaptiveDirector
{
    public AdaptiveDirector()
    {
        var creator = new TxtCreator();
        builder = creator.Create();
    }
    private readonly Builder builder;

    public void Construct()
    {
        builder.CreateReport();
        builder.SetHeader("Header");
        builder.SetBlock("Block");
        builder.SetEnding("Ending");
    }
}
