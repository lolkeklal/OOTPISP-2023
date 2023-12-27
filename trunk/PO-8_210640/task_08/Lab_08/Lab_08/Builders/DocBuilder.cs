namespace Lab_08.Builders;

public class DocBuilder : Builder
{
    public override void SetHeader(string header)
    {
        report.Header = header;
    }

    public override void SetBlock(string block)
    {
        report.Block = ToDoc(block);
        Console.WriteLine(nameof(DocBuilder));
    }

    public override void SetEnding(string ending)
    {
        report.Ending = ending;
    }

    private static string ToDoc(string block)
    {
        // some operations
        return block;
    }
}
