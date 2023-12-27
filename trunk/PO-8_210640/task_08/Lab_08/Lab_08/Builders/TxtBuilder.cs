namespace Lab_08.Builders;

public class TxtBuilder : Builder
{
    public override void SetHeader(string header)
    {
        report.Header = header;
    }

    public override void SetBlock(string block)
    {
        report.Block = ToTxt(block);
        Console.WriteLine(nameof(TxtBuilder));
    }

    public override void SetEnding(string ending)
    {
        report.Ending = ending;
    }

    private static string ToTxt(string block)
    {
        // some operations
        return block;
    }
}
