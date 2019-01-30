using System;
using System.Text;
using System.IO;

namespace Home {
	class Home {
		static void Main() {
			String[] ot = Console.ReadLine().Split(null);
			int n = int.Parse(ot[0]), x = int.Parse(ot[1]);

			ot = Console.ReadLine().Split(null);
			int[] aa = new int[ot.Length];
			for (int i = 0; i < n; ++i) aa[i] = Convert.ToInt32(ot[i]);

			bool[] cts = new bool[101];

			for (int i = 0; i < n; ++i) cts[aa[i]] = true;

			int ct = countBelow(cts, n, x);

			if (ct > 0) {
				if (cts[x]) ++ ct;
				Console.WriteLine(ct);
			}
			else {
				if (cts[x]) ++ct;
				Console.WriteLine(ct);
			}
		}

		static int countBelow(bool[] cts, int n, int x) {
			int count = 0;
			for (int i = 0; i < x; ++i) if (!cts[i]) ++count;
			return count;
		}
	}
}

