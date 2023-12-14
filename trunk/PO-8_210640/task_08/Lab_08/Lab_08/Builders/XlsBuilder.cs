namespace Lab_08.Builders;

public class XlsBuilder : Builder
{
    public override void SetHeader(string header)
    {
        report.Header = header;
    }

    public override void SetBlock(string block)
    {
        report.Block = ToXls(block);
        Console.WriteLine(nameof(XlsBuilder));
    }

    public override void SetEnding(string ending)
    {
        report.Ending = ending;
    }

    private static string ToXls(string block)
    {
        // some operations
        return block;
    }
}
