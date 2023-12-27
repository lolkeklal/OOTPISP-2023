namespace Lab_08.Builders;

public class HtmlBuilder : Builder
{
    public override void SetHeader(string header)
    {
        report.Header = header;
    }

    public override void SetBlock(string block)
    {
        report.Block = ToHtml(block);
        Console.WriteLine(nameof(HtmlBuilder));
    }

    public override void SetEnding(string ending)
    {
        report.Ending = ending;
    }

    private static string ToHtml(string block)
    {
        // some operations
        return block;
    }
}
