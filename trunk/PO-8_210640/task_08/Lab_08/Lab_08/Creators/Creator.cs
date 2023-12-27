using Lab_08.Builders;

namespace Lab_08.Creators;

public abstract class Creator
{
    public abstract Builder Create();

    public static Builder Create<T>() where T : Builder, new()
    {
        return new T();
    }
}
