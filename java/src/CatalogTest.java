import org.junit.*;

public class CatalogTest{
  private final Catalog catalog = new Catalog();
  final Entry entry = new Entry("potato", "chips");

  @Before public void fillTheCatalog(){
    catalog.add(entry);
  }

  @Test public void containAnAddedEntry(){
    assertTrue(catalog.contains(entry));
  }

  @Test public void indexesEntriesByName(){
    assertEquals(entry, catalog.entryFor("potato"));
    assertNull(catalog.entryFor("unknown*"));
  }

  @Test(expected=IllegalArgumentException.class)
  public void cannotAddTwoEntriesWithTheSameName(){
    catalog.add(new Entry("potato", "curry"));
  }

  @After public void doSomethingAfterTests(){
  }
}
