

public class DNA {
	static void subString(String str, int n)
	{
	    for (int len = 1; len <= n; len++)
	    {
	        String[] subs = new String[n-len + 1];
	        for (int i = 0; i <= n - len; i++)
	        {
	            int j = i + len - 1;
	            subs[i] = new String();	
	            subs[i] = str.substring(i, j + 1);
	        }
	        int count = 0;
	        for(int i = 0; i < subs.length; ++i)
	        {
	        	int j;
	        	for(j = 0; j < subs.length; j++)
	        		if(i != j && subs[i].contentEquals(subs[j]))
	        			break;
	        	
	        	if(j == subs.length)
	        		count++;
	        
	        }
	        if(count != 0) {
	        	System.out.println(len + " " + count);
	        	break;
	        }
	    }
	    
	}
	
	
	public static void main(String[] args) {
		String str = "atacggcgcacggagtgatctgctgtagttcgttccgataaattaagaagatacggcgcacggagtgatctgctgtagttcgttccgataaattaagaagatacggcgcacggagtgatctgctgtagttcgttccgataaattaagaagatacggcgcacggagtgatctgctgtagttcgttccgataaattaagaagatacggcgcacggagtgatctgctgtagttcgttccgataaattaagaagatacggcgcacggagtgatctgctgtagttcgttccgataaattaagaagatacggcgcacggagtgatctgctgtagttcgttccgataaattaagaagatacggcgcacggagtgatctgctgtagttcgttccgataaattaagaagatacggcgcacggagtgatctgctgtagttcgttccgataaattaagaagatacggcgcacggagtgatctgctgtagttcgttccgataaattaagaagatacggcgcacggagtgatctgctgtagttcgttccgataaattaagaagatacggcgcacggagtgatctgctgtagttcgttccgataaattaagaagatacggcgcacggagtgatctgctgtagttcgttccgataaattaagaagatacggcgcacggagtgatctgctgtagttcgttccgataaattaagaagatacggcgcacggagtgatctgctgtagttcgttccgataaattaagaagatacggcgcacggagtgatctgctgtagttcgttccgataaattaagaagatacggc";
	    subString(str, str.length());

	}

}
