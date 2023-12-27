using Lab_08.Builders;

namespace Lab_08.Creators;

public class TxtCreator : Creator
{
    public override Builder Create()
    {
        return new TxtBuilder();
    }
}
