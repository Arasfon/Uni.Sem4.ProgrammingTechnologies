using System.Threading.Tasks;

namespace TelecommsSimulation.Core;

public delegate Task AsyncEventHandler<in T>(object sender, T e);
