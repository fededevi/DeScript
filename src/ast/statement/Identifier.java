package ast.statement;

import java.util.Objects;

public class Identifier {
	String id;
	
	public Identifier(String id)
	{
		this.id = id;
	}


	public String toString()
	{
		return id;
	}
	
	@Override
	public boolean equals(Object other){
	    if (other == null) return false;
	    if (other == this) return true;
	    if (!(other instanceof Identifier))return false;
	    return id.equals(((Identifier)other).id);
	}
	
    @Override
    public int hashCode() {
        return Objects.hash(id);
    }

}
