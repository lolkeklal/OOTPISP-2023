namespace Lab_08.Builders;

public abstract class Builder
{
    protected Report report;

    public void CreateReport()
    {
        report = new Report();
    }

    public abstract void SetHeader(string header);
    public abstract void SetBlock(string block);
    public abstract void SetEnding(string ending);

    public Report GetReport()
    {
        return report;
    }
}
