defmodule BinarySearch do
  def search(list, key) do
    if list != Enum.sort(list) do
      raise ArgumentError, message: "list:"
    end

    do_search(Enum.with_index(list), key)
  end

  defp do_search([], _key), do: :not_found

  defp do_search(list, key) do
    middle = length(list) / 2 |> round

    {left, right} = Enum.split(list, middle)
    {item, index} = List.last(left)
    left = Enum.drop(left, -1)

    cond do
      key == item -> {:ok, index}
      key < item  -> do_search(left, key)
      key > item  -> do_search(right, key)
    end
  end
end