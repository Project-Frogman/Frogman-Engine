namespace Editor;




[Serializable]
public class AreaOfOperations
{
    public string? TargetGDKVersion { get; set; }
    public string? Tag { get; set; }
    public double[] Gravity { get; set; } = new double[3] { 0.0, -9.81, 0.0 };
    public Dictionary<string, string?> SceneGraphRootNodes { get; set; } = new(); // Key: Nickname, Value: Path
}
