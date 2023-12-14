using Lab_08.Builders;

namespace Lab_08.Creators;

public class DocCreator : Creator
{
    public override Builder Create()
    {
        return new DocBuilder();
    }
}
